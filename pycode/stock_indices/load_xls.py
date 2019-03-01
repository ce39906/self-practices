#-*- coding: utf-8 -*-
"""
File Name: load_xls.py
Author: ce39906
mail: ce39906@163.com
Created Time: 2019-03-01 11:35:07
"""
import pandas as pd
import numpy as np

def load_close_weight_xls(filename):
    print("loading ", filename)
    df = pd.read_excel(filename,
                       converters={'指数代码Index Code' : lambda x: str(x)})
    index_name = df['指数名称Index Name'].values[0]
    index_code = df['指数代码Index Code'].values[0]
    constituent_code = df['成分券代码Constituent Code'].values
    weight = df['权重(%)Weight(%)'].values
    
    n = weight.shape[0]
    constituent_code_2_weight = {}
    for i in range(n):
        constituent_code_2_weight[constituent_code[i]] = weight[i]
    return index_name, index_code, constituent_code_2_weight 

def load_cons_xls(filename):
    print("loading ", filename)
    sheet1_df = pd.read_excel(filename,
                              converters={'指数代码Index Code' : lambda x: str(x)})
    index_name = sheet1_df['指数名称Index Name'].values[0]
    index_code = sheet1_df['指数代码Index Code'].values[0]
    constituent_code = sheet1_df['成分券代码Constituent Code'].values
    sheet2_df = pd.read_excel(filename, sheet_name='weight')
    top10_code_2_weight = {}
    for index, row in sheet2_df.iterrows():
        code = row['代码']
        weight = row['权重']
        top10_code_2_weight[code] = weight
    
    total_count = constituent_code.shape[0]
    top10_weight_count = len(top10_code_2_weight.keys())
    
    top10_weight_sum = 0.0
    for top10_weight in top10_code_2_weight.values():
        top10_weight_sum += top10_weight
    
    default_weight = (100.0 - top10_weight_sum) / (total_count - top10_weight_count)
    constituent_code_2_weight = {}
    for i in range(total_count):
        code = constituent_code[i]
        if code in top10_code_2_weight:
            constituent_code_2_weight[code] = top10_code_2_weight[code]
        else:
            constituent_code_2_weight[code] = default_weight
    return index_name, index_code, constituent_code_2_weight
