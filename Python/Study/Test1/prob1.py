from ast import Sub
from re import A
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df1_1 = pd.read_excel(r"D:\code\Python\Study\Test1\附件1.xlsx", sheet_name="企业的订货量（m³）")
df1_2 = pd.read_excel(r"D:\code\Python\Study\Test1\附件1.xlsx", sheet_name="供应商的供货量（m³）")


df2 = pd.read_excel(r"D:\code\Python\Study\Test1\附件2.xlsx")

# A、B、C原材料订货量
A_push = []     
B_push = []
C_push = []

# A、B、C原材料供货量
A_get = []
B_get = []
C_get = []

for i in range(0, 401) :
    if (df1_1.loc[i].values[1] == 'A') :
        A_push.append(df1_1.loc[i].values)
        A_get.append(df1_2.loc[i].values)
    elif (df1_1.loc[i].values[1] == 'B') :
        B_push.append(df1_1.loc[i].values)
        B_get.append(df1_2.loc[i].values)
    else :
        C_push.append(df1_1.loc[i].values)
        C_get.append(df1_2.loc[i].values)
