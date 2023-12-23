local colorscheme = "catppuccin"

local dracula = require("dracula")
dracula.setup({
	transparent_bg = true,
	lualine_bg_color = "#44475a",
	italic_comment = true,
})

require("tokyonight").setup({
	style = "night",
	transparent = true,
	styles = {
		sidebars = "transparent",
		floats = "transparent",
	},
})

require("catppuccin").setup({
	flavour = "mocha", -- latte, frappe, macchiato, mocha
	background = { -- :h background
		light = "latte",
		dark = "mocha",
	},
	transparent_background = true, -- disables setting the background color.
})
local status_ok, _ = pcall(vim.cmd, "colorscheme " .. colorscheme)
if not status_ok then
	return
end
