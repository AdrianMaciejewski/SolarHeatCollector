import argparse
import csv

# Function to parse the data line and extract key-value pairs
def parse_data_line(line, order_of_keys):
    data = {}
    
    # Remove the prefix "[DATA] " and split the line by commas
    line = line.replace("[DATA] ", "")
    parts = line.split(',')
    
    # Process each part and extract the key and value
    for part in parts:
        # Split by the first colon to separate header and value
        key_value = part.split(':', 1)
        
        if len(key_value) == 2:
            # Strip any leading/trailing whitespace and assign the value
            key = key_value[0].strip()
            value = float(key_value[1].strip())
            data[key] = value
            if key not in order_of_keys:
                order_of_keys.append(key)
    
    return data

# Function to write the parsed data to a CSV file with dynamic headers while preserving order
def write_to_csv(data_lines, output_file):
    if not data_lines:
        print("No data to log.")
        return
    
    # The first line will define the header, so use the order of appearance of keys
    order_of_keys = []
    
    # Process all data lines and accumulate keys in order of appearance
    for data in data_lines:
        for key in data.keys():
            if key not in order_of_keys:
                order_of_keys.append(key)

    with open(output_file, mode='w', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=order_of_keys)
        writer.writeheader()  # Write header
        
        # Write each data row
        for data in data_lines:
            writer.writerow(data)
    
    print(f"Data successfully written to {output_file}")

# Main function
def main():
    # Setup command-line argument parsing
    parser = argparse.ArgumentParser(description="Process log file and save data to CSV.")
    parser.add_argument("input_log_file", help="The path to the input log file")
    parser.add_argument("output_csv_file", help="The path to the output CSV file")
    
    # Parse the arguments
    args = parser.parse_args()

    data_lines = []

    # Read the log file and extract the data lines
    with open(args.input_log_file, 'r') as file:
        for line in file:
            if line.startswith("[DATA]"):  # Process only lines that start with [DATA]
                parsed_data = parse_data_line(line, [])
                if parsed_data:
                    data_lines.append(parsed_data)

    # Write the extracted data to a CSV file
    write_to_csv(data_lines, args.output_csv_file)

# Run the main function
if __name__ == "__main__":
    main()
