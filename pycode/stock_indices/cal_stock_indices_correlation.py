#-*- coding: utf-8 -*-
"""
File Name: cal_stock_indices_correlation.py
Author: ce39906
mail: ce39906@163.com
Created Time: 2019-03-01 14:31:30
"""
import load_xls
import os
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

def load_data():
    stock_indices_data = {}
    constituent_codes = set()

    for filename in os.listdir('data'):
        if not filename.endswith('.xls'):
            continue

        if len(filename) == 21:
            index_name, index_code, constituent_code_2_weight = load_xls.load_close_weight_xls('data/' + filename)
        else:
            index_name, index_code, constituent_code_2_weight = load_xls.load_cons_xls('data/' + filename)
        
        for constituent_code in constituent_code_2_weight.keys():
            constituent_codes.add(constituent_code)
        
        stock_indices_data[index_name + '_' + str(index_code)] = constituent_code_2_weight
    
    return list(constituent_codes), stock_indices_data

def vectorization(constituent_codes, stock_indices_data):
    n = len(constituent_codes)
    df = pd.DataFrame()
    for stock_index_name, weights in stock_indices_data.items():
        vector = [0.0] * n
        for i in range(n):
            code = constituent_codes[i]
            if code in weights:
                vector[i] = weights[code] / 100.0
        df[stock_index_name] = vector
    
    return df

def plot_corr_heatmap(df):
    corr = df.corr()
    f, ax = plt.subplots(figsize=(15, 15))
    sns.heatmap(corr,
                cmap='rainbow',
                linewidths=0.05,
                ax=ax,
                square=True,
                annot=True)
    f.savefig('stock_indices_corr_heatmap.png')

def main():
    constituent_codes, stock_indices_data = load_data()
    df = vectorization(constituent_codes, stock_indices_data)
    plot_corr_heatmap(df)

if __name__ == '__main__':
    main()

