import pandas as pd

# Load the CSV file
input_file = 'input.csv'  # Change this to your input file path
output_file = 'filtered_output.csv'  # Change this to your desired output file path

# Read the CSV file
df = pd.read_csv(input_file, sep=';')

df['x(m)'] -= 30

# Filter the DataFrame to remove rows where x and y are between -20 and 20
filtered_df = df[~((df['x(m)'] >= -50) & (df['x(m)'] <= 50) & 
                   (df['y(m)'] >= -50) & (df['y(m)'] <= 50))]

# Save the filtered DataFrame to a new CSV file
filtered_df.to_csv(output_file, sep=';', index=False)

print(f"Filtered data saved to {output_file}.")
