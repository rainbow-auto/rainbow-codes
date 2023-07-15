from tkinter import *
from functools import partial

import pygetwindow as gw
import pyperclip
import requests
from bs4 import BeautifulSoup

def getProblems():
    titles = gw.getAllTitles()

    problems = []

    for curr in titles:
        if (len(curr) > 4 and curr[-4:] == 'Edge') or (len(curr) > 6 and curr[-6] == 'Chrome'):
            if '洛谷' in curr:
                i = 0
                while curr[i] != ' ':
                    i += 1

                problems.append(curr[:i])

    return problems

def getSample(problem):

    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 Edg/114.0.1823.79'
    }

    luogu_url = 'https://www.luogu.com.cn/problem/' + problem[1]
    luogu_page = requests.get(url = luogu_url, headers = headers)
    soup = BeautifulSoup(luogu_page.text, 'lxml')
    
    sample_list_nd = soup.find_all( name = 'pre', attrs = {'data-v-1dc3ddfc':''} ) # no divided
    
    sample_list = []

    for i, sample in enumerate (sample_list_nd):
        if i % 2 == 0:
            sample_list.append ('输入' + str(i))
            sample_list.append (sample.text)
        elif i % 2 == 1:
            sample_list.append ('输出' + str(i))
            sample_list.append (sample.text)

    return sample_list

class choosePage:
    
    def choose (self, curr):
        self.choice = curr
        self.root.destroy()

    def __init__(self, choice_list):
        self.root = Tk()
        self.root.title('洛谷刷题小工具')

        self.label = Label(self.root, text = '请选择: ')
        self.label.pack()
        
        for curr in choice_list:
            button_now = Button(self.root, text = curr, command = partial(self.choose, [self, curr]))
            button_now.pack()
        
        self.root.mainloop()

if __name__ == '__main__':
    choose_problem_page = choosePage(getProblems())
    
    sample_list = getSample(choose_problem_page.choice)

    choose_sample_page = choosePage(sample_list)

    pyperclip.copy (choose_sample_page.choice[1])