from PIL import Image

PicPath = "./白月魁.png"

img = Image.open(PicPath)

out = img.transpose(Image.FLIP_LEFT_RIGHT)

newname = "./白月魁_l_r.jpg"

out.save(newname)