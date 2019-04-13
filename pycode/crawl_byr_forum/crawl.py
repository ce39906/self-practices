#-*- coding: utf-8 -*-
"""
File Name: crawl.py
Author: ce39906
Mail: ce39906@163.com
Created Time: 2019-04-12 11:52:17
"""
from bs4 import BeautifulSoup
import requests

headers = {'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
           'Accept-Encoding': 'gzip, deflate, compress',
           'Accept-Language': 'en-us;q=0.5,en;q=0.3',
           'Cache-Control': 'max-age=0',
           'Connection': 'keep-alive',        
           'X-Requested-With': 'XMLHttpRequest',
           'User-Agent': 'Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/35.0.1916.153 Safari/537.36' }

def login():
    url = 'https://bbs.byr.cn/user/ajax_login.json'
    login_data = {'id': '****', 'passwd': '******'}
    session = requests.Session()
    req = session.post(url, data=login_data, headers=headers)
    return session

def crawl_board(session, board='Jump'):
    base_url = 'https://bbs.byr.cn/board/'
    url = base_url + board
    content = session.get(url, headers=headers).content
    return content

def parse_page(content):
    soup = BeautifulSoup(content, features="lxml")
    spans = soup.findAll('span', {'class' : 'n-left'})
    text = str(spans[0])
    cur_user_prefix = "共有"
    cur_user_suffix = "人"
    prefix_idx = text.find(cur_user_prefix)
    suffix_idx = text.find(cur_user_suffix, prefix_idx)
    cur_user_num = text[prefix_idx + len(cur_user_prefix) : suffix_idx]

    max_user_prefix = "最高"
    max_user_suffix = "人"
    prefix_idx = text.find(max_user_prefix, suffix_idx)
    suffix_idx = text.find(max_user_suffix, prefix_idx)
    max_user_num = text[prefix_idx + len(max_user_prefix) : suffix_idx]

    cur_post_prefix = "帖数"
    cur_post_suffix = "<"
    prefix_idx = text.find(cur_post_prefix, suffix_idx)
    suffix_idx = text.find(cur_post_suffix, prefix_idx)
    post_num = text[prefix_idx + len(cur_post_prefix) : suffix_idx]
    
    return int(cur_user_num), int(max_user_num), int(post_num)

def run(boards):
    session = login()
    res = {}
    for board in boards:
        content = crawl_board(session, board)
        res[board] = parse_page(content)

    return res

def main():
    session = login()
    jump_content = crawl_board(session, 'Jump')
    print (parse_page(jump_content))
    job_content = crawl_board(session, 'JobInfo')
    print (parse_page(job_content))

if __name__ == '__main__':
    main()
