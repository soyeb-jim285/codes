import matplotlib.pyplot as plt


def visualize_polygon():
    # Read number of points
    n = int(input("Enter the number of points: "))
    points = []

    # Read the points
    print("Enter the points as 'x y' (one per line):")
    for _ in range(n):
        x, y = map(int, input().split())
        points.append((x, y))

    # Add the first point again to close the polygon
    points.append(points[0])

    # Separate x and y coordinates for plotting
    x_coords, y_coords = zip(*points)

    # Plot the polygon
    plt.figure(figsize=(8, 6))
    plt.plot(x_coords, y_coords, "-o", label="Polygon")
    plt.fill(x_coords, y_coords, alpha=0.3, label="Filled Polygon")

    # Add labels and grid
    plt.title("Polygon Visualization")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.grid(True)
    plt.axhline(0, color="black", linewidth=0.5)
    plt.axvline(0, color="black", linewidth=0.5)
    plt.legend()

    # Show the plot
    plt.show()


# Run the function
visualize_polygon()
