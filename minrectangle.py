def solution(sizes):
    width = height = 0
    for size in sizes:
        if size[1] > size[0] : 
            size[0], size[1] = size[1], size[0]
        width = max(size[0],width)
        height = max(size[1],height)
    return width * height