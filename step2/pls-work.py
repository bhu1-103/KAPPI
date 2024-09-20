import pandas as pd

# Load the CSV file
input_file = 'input.csv'  # Change this to your input file path
output_file = 'filtered_output.csv'  # Change this to your desired output file path

# Read the CSV file
df = pd.read_csv(input_file, sep=';')

# Shift all x positions by -30
df['x(m)'] -= 30

# Filter the DataFrame to remove rows where x and y are between -50 and -50
# except when the node_code contains "AP"
filtered_df = df[~((df['x(m)'] >= -50) & (df['x(m)'] <= 50) &
                   (df['y(m)'] >= -50) & (df['y(m)'] <= 50) &
                   (~df['node_code'].str.contains("AP"))) ]

# Save the filtered DataFrame to a new CSV file
filtered_df.to_csv(output_file, sep=';', index=False)

print(f"Filtered data saved to {output_file}.")
