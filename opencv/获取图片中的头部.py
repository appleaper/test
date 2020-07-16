#cv2——python截取图片的头部
#1.先通过cv2.__ file __ 找到haarcascade_frontalface_default.xml的位置
#2.截图图片中头部

import cv2
import random
# print(cv2.__file__)

# 改变亮度与对比度
def relight(img, alpha=1, bias=0):
    w = img.shape[1]
    h = img.shape[0]
    #image = []
    for i in range(0,w):
        for j in range(0,h):
            for c in range(3):
                tmp = int(img[j,i,c]*alpha + bias)
                if tmp > 255:
                    tmp = 255
                elif tmp < 0:
                    tmp = 0
                img[j,i,c] = tmp
    return img

classifier = cv2.CascadeClassifier('F:\\life\\conda\\envs\\test\\Lib\\site-packages\\cv2\\data\\haarcascade_frontalface_default.xml')
img = cv2.imread('./1.jpg')
gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)#转灰度图
faces = classifier.detectMultiScale(gray_img, 1.3, 5)#用分类器获取脸部
for f_x, f_y, f_w, f_h in faces:  # 截取原来图像的脸部
    face = img[f_y:f_y + f_h, f_x:f_x + f_w]
    face = cv2.resize(face, (128, 128))
    face = relight(face, random.uniform(0.5, 1.5), random.randint(-50, 50))  # 重新调亮度
    cv2.imwrite('./2.jpg', face)
