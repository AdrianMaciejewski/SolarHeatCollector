import argparse
import pandas as pd
import matplotlib.pyplot as plt

def main():
    # Set up argument parser
    parser = argparse.ArgumentParser(description="Plot specified columns from a CSV file.")
    parser.add_argument('--csv_file', type=str, required=True, help='Path to the CSV file.')
    parser.add_argument('--column_x', type=int, required=True, help='Index of the column for the x-axis.')
    parser.add_argument('--column_y', type=int, nargs='+', required=True, help='Indices of the columns for the y-axis (space-separated).')
    parser.add_argument('--output', type=str, help='Path to save the output plot (e.g., plot.png).')
    parser.add_argument('--title', type=str, help='Title of the plot.')
    parser.add_argument('--xlabel', type=str, help='Label for the x-axis.')
    parser.add_argument('--ylabel', type=str, help='Label for the y-axis.')
    
    args = parser.parse_args()

    # Load the CSV file
    try:
        data = pd.read_csv(args.csv_file)
    except FileNotFoundError:
        print(f"Error: File '{args.csv_file}' not found.")
        return

    # Check if columns are valid
    max_col_index = len(data.columns) - 1
    if args.column_x > max_col_index or any(y > max_col_index for y in args.column_y):
        print(f"Error: Column indices out of range. File '{args.csv_file}' has {len(data.columns)} columns.")
        return

    # Extract x data
    x_data = data.iloc[:, args.column_x]

    # Plot each specified y column against x
    plt.figure(figsize=(10, 6))
    for y_col in args.column_y:
        y_data = data.iloc[:, y_col]
        plt.plot(x_data, y_data, marker='o', label=data.columns[y_col])

    # Configure plot
    plt.xlabel(args.xlabel)
    plt.ylabel(args.ylabel)
    plt.title(args.title)
    plt.legend()
    plt.grid(True)

    # Save to file or show the plot
    if args.output:
        plt.savefig(args.output, dpi=300)
        print(f"Plot saved to '{args.output}'.")
    else:
        plt.show()

if __name__ == "__main__":
    main()
