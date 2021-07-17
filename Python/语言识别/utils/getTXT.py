import os

def getTXT():
    dir_list = os.listdir("../data_thchs30/data/") # 获取文件夹下的所有数据
    # print((dir_list))
    temp = []
    for i in dir_list:
        if i.endswith(".trn"):
            temp.append(i)
    # len(temp)
    with open("../data_thchs30/data.txt", "w") as f:
        for i in temp:
            with open("../data_thchs30/data/"+i,"r", encoding="utf8") as f_:
                f_str = f_.readlines()
                f.write(i[:-4]+"\t"+f_str[1].strip()+"\t"+f_str[0].strip().replace(" ","")+"\n")

if __name__ =="__main__":
    getTXT()