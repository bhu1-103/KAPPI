import pandas as pd
import glob
import numpy as np
import os

input_path = r"../step1/x-y_output/"
output_path = r"z_output/"

os.makedirs(output_path, exist_ok=True)

csv_files = glob.glob(os.path.join(input_path, "*.csv"))

for number in range(100):
    file_number = f"{number:03d}"
    
    matching_file = None
    for file in csv_files:
        filename = os.path.basename(file)
        if filename.startswith(file_number) and filename.endswith(".csv"):
            matching_file = file
            break
    
    if matching_file:
        print(f"Processing file: {matching_file}")
        
        df = pd.read_csv(matching_file, delimiter=';')
        
        print(f"Columns in {matching_file}: {df.columns.tolist()}")
        
        z_values = np.around(np.random.uniform(3, 10, size=len(df)), decimals=4)
        df['z(m)'] = z_values
        
        output_file = os.path.join(output_path, f"input_nodes_copy_deployment_{file_number}.csv")
        
        df.to_csv(output_file, sep=';', index=False)
        print(f"Saved to: {output_file}")  
    else:
        print(f"No file found with the number {file_number}.")
