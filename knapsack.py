import time
start_time = time.time()
def knapSack(Capacity, Item, n): 

	if n == 0 or Capacity == 0 : 
		return 0

	if (Item[n-1][1] > Capacity): 
		return knapSack(Capacity, Item, n-1) 

	else: 
		return max(Item[n-1][0] + knapSack(Capacity-Item[n-1][1], Item, n-1), 
				knapSack(Capacity, Item, n-1)) 

n = int(input("Number of Items : "))
Item = []
for x in range(n):
	newItem = [0,0]
	newItem[0] = int(input("\tValue: "))
	newItem[1] = int(input("\tWeight: "))
	Item.append(newItem)

Capacity = int(input("Capacity of Bag: "))
Item.sort()
print "Maximum Value of bag: "+str(knapSack(Capacity, Item, n)) 
print "Completed in "+str(time.time() - start_time)+" Seconds"