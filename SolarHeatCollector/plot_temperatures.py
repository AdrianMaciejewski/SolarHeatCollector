import pandas as pd
import matplotlib.pyplot as plt
import sys
import os

def plot_temperatures(input_csv, output_file="temperature_graph.png"):
    # Load the CSV file into a DataFrame
    try:
        data = pd.read_csv(input_csv)
    except FileNotFoundError:
        print(f"Error: File '{input_csv}' not found.")
        sys.exit(1)

    # Check for required columns
    required_columns = ["Time (ms)", "Rod Temperature", "Green Cord Temperature", "Average Temperature"]
    for column in required_columns:
        if column not in data.columns:
            print(f"Error: Missing required column '{column}' in the CSV file.")
            sys.exit(1)

    # Convert "Time (ms)" to seconds
    data["Time (s)"] = data["Time (ms)"] / 1000.0

    # Plot the data
    plt.figure(figsize=(12, 6))
    plt.plot(data["Time (s)"], data["Rod Temperature"], label="Rod Temperature", marker='o')
    plt.plot(data["Time (s)"], data["Green Cord Temperature"], label="Green Cord Temperature", marker='s')
    plt.plot(data["Time (s)"], data["Average Temperature"], label="Average Temperature", marker='^')

    # Customize the graph
    plt.title("Temperatures Over Time")
    plt.xlabel("Time (s)")
    plt.ylabel("Temperature (°C)")
    plt.legend()
    plt.grid(True)

    # Save the graph to the specified file path
    plt.savefig(output_file)
    print(f"Graph saved as '{output_file}'.")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python plot_temperatures.py <input_csv> <output_file>")
        sys.exit(1)

    input_csv = sys.argv[1]
    output_file = sys.argv[2]
    plot_temperatures(input_csv, output_file)
