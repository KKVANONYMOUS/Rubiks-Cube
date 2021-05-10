import cv2
import numpy as np 

def face_color(image):
	hsv=cv2.cvtColor(crop,cv2.COLOR_BGR2HSV)

	lower_red = np.array([0,70,50])
	upper_red = np.array([10,255,255])
	lowerred = np.array([170,20,50])
	upperred = np.array([180,255,255])


	mask1 = cv2.inRange(hsv, lower_red,upper_red)
	mask2 = cv2.inRange(hsv, lowerred,upperred)
	maskr = mask1 + mask2
	mask(maskr, 'red')

	masky = cv2.inRange(hsv, np.array([22,40,40]),np.array([35,255,255]))
	mask(masky , 'yellow')

	masko = cv2.inRange(hsv , np.array([12,40,40]),np.array([20,255,255]))
	mask(masko , 'orange')

	maskg = cv2.inRange(hsv , np.array([35,40,40]),np.array([85,255,255]))
	mask(maskg , 'green')

	maskb = cv2.inRange(hsv , np.array([90,40,40]),np.array([125,255,255]))
	mask(maskb , 'blue')

	maskw = cv2.inRange(hsv , np.array([0,0,215]),np.array([1,1,255]))
	mask(maskw , 'white')




def mask(image , color)	:
	kernel = np.ones((5,5),np.uint8)
	image = cv2.erode(image,kernel,iterations = 1)
	contour,_=cv2.findContours(image,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

	for cnt in contour:
		area=cv2.contourArea(cnt)
		if (area<1000):
			continue
		M = cv2.moments(cnt)
		cx =0
		cy=0
		if M["m00"] != 0:
			cx=int(M["m10"]/M["m00"])
			cy=int(M["m01"]/M["m00"])
		p =cy//200
		q=cx//200
		if (color == 'red'):
			b[p][q]=1
		if (color == 'white'):
			b[p][q]=0
		if (color == 'green'):
			b[p][q]=2
		if (color == 'blue'):
			b[p][q]=3
		if (color == 'orange'):
			b[p][q]=4
		if (color == 'yellow'):
			b[p][q]=5																	

face_images= ["1.jpeg","2.jpeg","3.jpeg","4.jpeg","5.jpeg","6.jpeg"]
for i in face_images:
	f = cv2.imread(i)
	r = cv2.selectROI(f)
	f = f[int(r[1]):int(r[1]+r[3]),int(r[0]):int(r[0]+r[2])]
	cv2.imshow('image',f)
	key = cv2.waitKey(0)
	if(key == 27):
		cv2.destroyAllWindows()
	crop = cv2.resize(f,(600,600))
	b =np.zeros((3,3),dtype=int)
	face_color(crop)
	print(b)
	content=str(b)
	with open('color.txt','a+') as file:
		file.write(content)
