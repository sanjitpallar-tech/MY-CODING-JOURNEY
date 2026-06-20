size = 15

for y in range(size, -size, -1):

    for x in range(-size, size + 1):

        normalized_x = x / (size * 0.7)
        normalized_y = y / (size * 0.6)

        expression = (normalized_x**2 + normalized_y**2 - 1)**3 - (normalized_x**2) * (normalized_y**3)

        if expression <= 0.0:
            print("*", end="")
        else:
            print(" ", end="")


            print()
