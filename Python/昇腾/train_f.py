import cv2
import matplotlib.pyplot as plt

# 读取图片，第二个参数：1 代表彩色图片，0 代表灰度图片
im = cv2.imread(r"./baiyuekui.png",1)
#此处用 opencv 读取图像，并用 matplotlib 显示，这个图像并不是传统颜色，
#因为 opencv 读取是按照 BGR 色彩通道读取，而 matplotlib 显示是按照 RGB 通道显示。
plt.figure("Text") # 图像窗口名称
plt.imshow(im)
plt.axis('on') # 关掉坐标轴为 off
plt.title('image') # 图像题目
plt.show()