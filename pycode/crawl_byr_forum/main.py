#-*- coding: utf-8 -*-
"""
File Name: main.py
Author: ce39906
Mail: ce39906@163.com
Created Time: 2019-04-13 08:00:27
"""
import time
import crawl
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from hire_info_db import HireInfo, HireInfoDB
from cos_client import TencentCloudClient

def crawl_byr():
    boards = ['Jump', 'JobInfo']
    crawled_data = crawl.run(boards)
    return crawled_data

def insert_record(crawled_data):
    date = time.strftime('%Y-%m-%d %H:%M:%S')
    for board, item in crawled_data.items():
        cur_user_num = item[0]
        max_user_num = item[1]
        cur_post_num = item[2]
        hire_info = HireInfo(board,
                             date, 
                             cur_user_num, 
                             max_user_num,
                             cur_post_num)
        hire_info_db = HireInfoDB()
        hire_info_db.insert(hire_info)

def select_former_data(board, days):
    hire_info_db = HireInfoDB()
    data = hire_info_db.select_by_board(board, days)
    return data

def plot(data, board):
    dates = [str(x[2]) for x in data]
    cur_user_nums = [x[3] for x in data]
    cur_post_nums = [x[5] for x in data]
    d = {'dates' : dates, 
         'cur_user_num' : cur_user_nums,
         'cur_post_num' : cur_post_nums}
    
    df = pd.DataFrame(d)
    plt.cla()
    ax = plt.gca()
    df.plot(title=board,
            kind='line',
            x='dates', 
            y='cur_user_num', 
            color='red',
            marker='o',
            label='online_user_num',
            ax=ax)
    df.plot(kind='line',
            x='dates',
            y='cur_post_num',
            color='green', 
            marker='x',
            label='post_num',
            ax=ax)

    plt.savefig(board + '.png')

def main():
    crawled_data = crawl_byr()
    insert_record(crawled_data)
    client = TencentCloudClient()
    days = 7
    boards = ['Jump', 'JobInfo']
    for board in boards:
        data = select_former_data(board, days)
        if len(data) < days:
            continue
        plot(data, board)
        client.upload_file(board + '.png')

if __name__ == '__main__':
    main()
