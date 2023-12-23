local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
	vim.fn.system({
		"git",
		"clone",
		"--filter=blob:none",
		"https://github.com/folke/lazy.nvim.git",
		"--branch=stable", -- latest stable release
		lazypath,
	})
end
vim.opt.rtp:prepend(lazypath)

require("lazy").setup({
	"nvim-lua/plenary.nvim", -- Useful lua functions used by lots of plugins
	"windwp/nvim-autopairs", -- Autopairs, integrates with both cmp and treesitter
	"NvChad/nvim-colorizer.lua",
	"numToStr/Comment.nvim",
	"zbirenbaum/copilot.lua",
	"ThePrimeagen/vim-be-good",
	"tpope/vim-fugitive",
	{
		"zbirenbaum/copilot-cmp",
		config = function()
			require("copilot_cmp").setup()
		end,
	},
	{ "echasnovski/mini.nvim", version = false },
	{
		"utilyre/barbecue.nvim",
		name = "barbecue",
		version = "*",
		dependencies = {
			"SmiteshP/nvim-navic",
			"nvim-tree/nvim-web-devicons", -- optional dependency
		},
		opts = {
			theme = "tokyonight",
		},
	},
	{
		"j-hui/fidget.nvim",
	},
	{
		"NeogitOrg/neogit",
		dependencies = {
			"nvim-lua/plenary.nvim", -- required
			"nvim-telescope/telescope.nvim", -- optional
			"sindrets/diffview.nvim", -- optional
			"ibhagwan/fzf-lua", -- optional
		},
		config = true,
	},
	{
		"stevearc/dressing.nvim",
		event = "VeryLazy",
		opts = {
			input = { enabled = true },
			select = { enabled = true },
		},
	},
	{
		"debugloop/telescope-undo.nvim",
		dependencies = { -- note how they're inverted to above example
			{
				"nvim-telescope/telescope.nvim",
				dependencies = { "nvim-lua/plenary.nvim" },
			},
		},
		keys = {
			{ -- lazy style key map
				"<leader>u",
				"<cmd>Telescope undo<cr>",
				desc = "undo history",
			},
		},
		opts = {
			-- don't use `defaults = { }` here, do this in the main telescope spec
			extensions = {
				undo = {
					-- telescope-undo.nvim config, see below
				},
				-- no other extensions here, they can have their own spec too
			},
		},
		config = function(_, opts)
			-- Calling telescope's setup from multiple specs does not hurt, it will happily merge the
			-- configs for us. We won't use data, as everything is in it's own namespace (telescope
			-- defaults, as well as each extension).
			require("telescope").setup(opts)
			require("telescope").load_extension("undo")
		end,
	},
	{ "JoosepAlviste/nvim-ts-context-commentstring" },
	"HiPhish/rainbow-delimiters.nvim",
	{
		"iamcco/markdown-preview.nvim",
		cmd = { "MarkdownPreviewToggle", "MarkdownPreview", "MarkdownPreviewStop" },
		ft = { "markdown" },
		build = function()
			vim.fn["mkdp#util#install"]()
		end,
	},
	{
		"nvim-tree/nvim-tree.lua",
		version = "*",
		lazy = false,
		dependencies = {
			"nvim-tree/nvim-web-devicons",
		},
		config = function()
			require("nvim-tree").setup({})
		end,
	},
	{
		"goolord/alpha-nvim",
		event = "VimEnter",
		opts = function()
			local dashboard = require("alpha.themes.dashboard")
			local logo = [[
				██╗      █████╗ ███████╗██╗   ██╗          Z
				██║     ██╔══██╗╚══███╔╝╚██╗ ██╔╝      Z
				██║     ███████║  ███╔╝  ╚████╔╝    z
				██║     ██╔══██║ ███╔╝    ╚██╔╝   z
				███████╗██║  ██║███████╗   ██║
				╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝
				]]

			dashboard.section.header.val = vim.split(logo, "\n")
      -- stylua: ignore
      dashboard.section.buttons.val = {
        dashboard.button('n', '  New file', ':ene <BAR> startinsert <CR>'),
        dashboard.button('r', '  Recent files', ':Telescope oldfiles <CR>'),
        dashboard.button('f', '󰥨  Find file', ':Telescope find_files <CR>'),
        dashboard.button('g', '󰱼  Find text', ':Telescope live_grep <CR>'),
        dashboard.button('s', '  Restore Session', [[:lua require('persistence').load() <cr>]]),
        dashboard.button('l', '󰒲  Lazy', ':Lazy<CR>'),
        dashboard.button('q', '  Quit', ':qa<CR>'),
      }
			for _, button in ipairs(dashboard.section.buttons.val) do
				button.opts.hl = "AlphaButtons"
				button.opts.hl_shortcut = "AlphaShortcut"
			end
			dashboard.section.header.opts.hl = "AlphaHeader"
			dashboard.section.buttons.opts.hl = "AlphaButtons"
			dashboard.section.footer.opts.hl = "AlphaFooter"
			dashboard.opts.layout[1].val = 7
			return dashboard
		end,
		config = function(_, dashboard)
			-- close Lazy and re-open when the dashboard is ready
			if vim.o.filetype == "lazy" then
				vim.cmd.close()
				vim.api.nvim_create_autocmd("User", {
					pattern = "AlphaReady",
					callback = function()
						require("lazy").show()
					end,
				})
			end

			require("alpha").setup(dashboard.opts)

			vim.api.nvim_create_autocmd("User", {
				pattern = "LazyVimStarted",
				callback = function()
					local stats = require("lazy").stats()
					local ms = (math.floor(stats.startuptime * 100 + 0.5) / 100)
          -- stylua: ignore
          dashboard.section.footer.val = '⚡ ' .. stats.count .. ' plugins loaded in ' .. ms .. 'ms'
					pcall(vim.cmd.AlphaRedraw)
				end,
			})
		end,
	},
	"akinsho/bufferline.nvim",
	{
		"folke/noice.nvim",
		event = "VeryLazy",
		opts = {
			-- add any options here
		},
		dependencies = {
			-- if you lazy-load any plugin below, make sure to add proper `module="..."` entries
			"MunifTanjim/nui.nvim",
			-- OPTIONAL:
			--   `nvim-notify` is only needed, if you want to use the notification view.
			--   If not available, we use `mini` as the fallback
			"rcarriga/nvim-notify",
		},
	},
	"moll/vim-bbye",
	"nvim-lualine/lualine.nvim",
	"akinsho/toggleterm.nvim",
	"ahmedkhalf/project.nvim",
	"lewis6991/impatient.nvim",
	"lukas-reineke/indent-blankline.nvim",
	"folke/which-key.nvim",
	-- Colorschemes
	{ "catppuccin/nvim", name = "catppuccin", priority = 1000 },
	"folke/tokyonight.nvim",
	"Mofiqul/dracula.nvim",
	"lunarvim/darkplus.nvim",
	-- Cmp
	"hrsh7th/nvim-cmp", -- The completion plugin
	"hrsh7th/cmp-buffer", -- buffer completions
	"hrsh7th/cmp-path", -- path completions
	"saadparwaiz1/cmp_luasnip", -- snippet completions
	"hrsh7th/cmp-nvim-lsp",
	"hrsh7th/cmp-nvim-lua",
	-- Snippets
	"L3MON4D3/LuaSnip", --snippet engine
	"soyeb-jim285/friendly-snippets", -- a bunch of snippets to use
	-- LSP
	"neovim/nvim-lspconfig", -- enable LSP
	"williamboman/mason.nvim", -- simple to use language server installer
	"williamboman/mason-lspconfig.nvim",
	"jose-elias-alvarez/null-ls.nvim", -- for formatters and linters
	"RRethy/vim-illuminate",
	-- Telescope
	"nvim-telescope/telescope.nvim",
	-- Treesitter
	"nvim-treesitter/nvim-treesitter",
	-- Git
	"lewis6991/gitsigns.nvim",
})

require("colorizer").setup()
-- require("mini.animate").setup()
