import multiprocessing
import time
import multiprocessing as mp
from multiprocessing import Pool, Process
import os
import math

def factorial1(num):     #Функція для підрахунку факторіалу з використанням циклу for
    result = 1
    for i in range (1, num + 1):
        result *= i
    return result
    
def parallel_factorial1():
    area = [5, 10, 15, 20, 25, 50]
    pool = multiprocessing.Pool(8)
    output = pool.map(factorial1, area)
    for i in range(len(output)):
        print("Факторіал числа ", area[i], "=", output[i])
    pool.close()
    pool.join()
    
def ordinary_factorial1():
    area = [5, 10, 15, 20, 25, 50]
    result = []
    for i in range(len(area)):
        result.append(factorial1(area[i]))
    for i in range(len(result)):
        print("Факторіал числа ", area[i], "=", result[i])
        
        
def factorial2(num):      #Функція для підрахунку факторіалу з використанням рекурсії
    if num == 0:
        return 1
    else:
        return num * factorial2(num - 1)
    
def parallel_factorial2():
    area = [5, 10, 15, 20, 25, 50]
    pool = multiprocessing.Pool(8)
    output = pool.map(factorial2, area)
    for i in range(len(output)):
        print("Факторіал числа ", area[i], "=", output[i])
    pool.close()
    pool.join()
    
def ordinary_factorial2():
    area = [5, 10, 15, 20, 25, 50]
    result = []
    for i in range(len(area)):
        result.append(factorial2(area[i]))
    for i in range(len(result)):
        print("Факторіал числа ", area[i], "=", result[i])
        
def tree(left, right):     #Функція для побудови дерева
    if left > right:
        return 1;
    if left == right:
        return left;
    if right - left == 1:
        return left * right;
    middle = round((left + right) / 2);
    return tree(left, middle) * tree(middle + 1, right)

def factorial3(num):      #Функція для підрахунку факторіалу з використанням алгоритму обчислення деревом
    if num < 0:
        return 0;
    if num == 0:
        return 1;
    if num == 1 or num == 2:
        return num;
    return tree(2, num);

def parallel_factorial3():
    area = [5, 10, 15, 20, 25, 50]
    pool = multiprocessing.Pool(8)
    out = pool.map(factorial3, area)
    for i in range(len(out)):
        print("Факторіал числа ", area[i], "=", out[i])
    pool.close()
    pool.join()
    
def ordinary_factorial3():
    area = [5, 10, 15, 20, 25, 50]
    result = []
    for i in range(len(area)):
        result.append(factorial3(area[i]))
    for i in range(len(result)):
        print("Факторіал числа ", area[i], "=", result[i])
