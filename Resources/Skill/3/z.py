import os
file_list = os.listdir(os.getcwd())
file_list.sort()
i = 1
for file in file_list:
    fileName = str(i)+".png"
    print(fileName[-3:])
    if (fileName != "png"):
        os.rename(file,fileName)
        i += 1
