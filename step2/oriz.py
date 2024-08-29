import pandas as pd
import glob

import numpy as np

# getting csv files from the folder MyProject
count=0
path = r"../step1/x-y_output/"
# read all the files with extension .csv
f1 = glob.glob(path + "/*.csv")

path3 =r"z_output/"
#print('File names:' , f1)

# for loop to iterate all csv files
for file1 in f1:


            df3 = pd.read_csv(file1,delimiter=';')
            df3 = df3.drop(columns=["node_code","node_type","wlan_code","x(m)", "y(m)","z(m)"])

            columns2 = ["node_code","node_type","wlan_code","x(m)","y(m)"]
            df1 = pd.read_csv(file1,delimiter=';',usecols=columns2)
            
            data = np.around(np.random.uniform(3, 10, size=300),decimals=4)
            df2 = pd.DataFrame(data, columns=['z(m)'])



            df_all_rows = pd.merge(df1, df2, left_index=True,right_index=True)
            df_all_rows2 = pd.merge(df_all_rows, df3, left_index=True,right_index=True)
            
            df_all_rows2.len=min(len(df1),len(df2))
        
            name = path3 + "input_nodes_copy_deployment_00" + str(count) +".csv"
            name1 = path3 + "input_nodes_copy_deployment_0" + str(count) +".csv"
            name2 = path3 + "input_nodes_copy_deployment_" + str(count) +".csv"
        
            if count<=9:
                df_all_rows2.to_csv(name,sep=';',index=False)
            elif count<=99:
                df_all_rows2.to_csv(name1,sep=';',index=False)
            else:
                df_all_rows2.to_csv(name2,sep=';',index=False)

       
            count+=1
 
