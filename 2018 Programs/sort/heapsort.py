import random
from timer import timer
l = [random.random() for i in range(1000)]

@timer
def heap_sort(l):
    sorted_list = []
    heap = create_heap(l)
    current_heap_length = len(heap)
    while(current_heap_length != 0):
        root = heap[0]
        create_max_heap(root)
        min_node = heap[current_heap_length-1]
        #Swap largest and smallest nodes
        root.children,min_node.children = min_node.children,root.children
        root.value,min_node.value = min_node.value,root.value
        sorted_list.append(heap.pop().value)
        current_heap_length -= 1
    return sorted_list

class Child:
    def __init__(self,value):
        self.value = value

class Parent(Child):
    def __init__(self,value,children):
        super().__init__(value)
        self.children = children

def create_heap(l):
    heap = []
    current_index = None
    for index,value in enumerate(l):
        if index == 0:
            heap.append(Parent(value,[]))
            current_index = 0
        else:
            current_parent = heap[current_index]
            current_child = Parent(value,[])
            heap.append(current_child)
            if len(current_parent.children) < 2: current_parent.children.append(current_child)
            else:
                current_index += 1
                current_parent = heap[current_index]
                current_parent.children.append(current_child)
    return heap

def create_max_heap(root):
    original_children = root.children
    for child in original_children:
        if child.value > root.value:
            #Swap of values for root and child
            root.children,child.children = child.children,root.children
            root.value,child.value = child.value,root.value
    for child in root.children:
        create_max_heap(child)
