# Solar Heat Collector Project

This README provides an overview of the project, including its components, how to use the provided scripts, and setup instructions. The project consists of an Arduino-based system to control the openness of shades in a solar heat collector using PID control. The system logs data, which can be processed and visualized using Python scripts.

---

## Project Components

### 1. Arduino System
The system includes:
- **Temperature Sensors**: Measures `Rod Temperature` and `Green Cord Temperature`.
- **Stepper Motor**: Controls the openness of the shades.
- **PID Controller**: Balances the system to maintain a target temperature.
- **Data Logger**: Logs system data during operation.

### 2. Python Tools
- **CSV Conversion Script**: Converts Arduino serial output logs to a structured CSV file.
- **Plotting Script**: Generates a graph of temperatures over time from the CSV file.

---

## Prerequisites

Before running the scripts, ensure you have the following installed:

- Python 3.x
- Required Python libraries:
  ```bash
  pip install pandas matplotlib
