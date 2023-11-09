import matplotlib.pyplot as plt

inOrderAVLTree = []
inOrderSplayTree = []
inOrderTree = []
shuffledAVLTree = []
shuffledSplayTree = []
shuffledTree = []
spotifyAVLTree = []
spotifySplayTree = []
spotifyTree = []


# Graph the results
def graph(name, depths):
    yTicksNeeded = False
    # Create a list of the sizes to use for the x-axis and positions for tick marks
    if name == "Spotify AVL Tree" or name == "Spotify Splay Tree" or name == "Spotify Tree":
        sizes = range(1, 4900, 1)
        xTickPositions = range(0, 4900, 500)
        if name == "Spotify Tree":
            yTickPositions = range(0, 5001, 500)
            yTicksNeeded = True;
    elif '99' in depths:
        # Need to create different y tick positions if depth values are too high to avoid overcrowding
        sizes = range(1, 101, 1)
        yTickPositions = range(10, 101, 10)
        xTickPositions = range(10, 101, 10)
        yTicksNeeded = True
    else:
        sizes = range(1, 101, 1)
        xTickPositions = range(10, 101, 10)
    # The third 1 signals to start at the first subplot (aka subplot 1 out of 1)
    ax = plt.subplot(111)
    ax.bar(sizes, depths, width=0.5, color='b', align='center')

    # Set the window title
    plt.gcf().canvas.manager.set_window_title(name)
    # Set the graph title
    plt.title(name)
    # Label the x-axis
    plt.xlabel('Value')
    # Make sure the x-axis tick marks/labels are at each 1
    plt.xticks(xTickPositions)
    # Label the y axis
    plt.ylabel('Depth')
    # Add y ticks if needed
    if yTicksNeeded:
        plt.yticks(yTickPositions)
    # Save the graph to a file
    new_name = name.replace(" ", "")
    plt.savefig('../images/' + new_name + '.png')
    # Display the graph in a new window
    plt.show()


try:
    infile = open("../data/inOrderAVLTree.csv", 'r')
    header = infile.readline()
    inOrderAVLTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(inOrderAVLTree)):
        inOrderAVLTree[index] = inOrderAVLTree[index].rstrip('\n')
    # Separate depths from values
    inOrderAVLDepths = []
    for i in inOrderAVLTree:
        inOrderAVLDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: inOrderAVLTree.csv cannot be found.')

graph("In Order AVL", inOrderAVLDepths)

try:
    infile = open("../data/inOrderSplayTree.csv", 'r')
    header = infile.readline()
    inOrderSplayTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(inOrderSplayTree)):
        inOrderSplayTree[index] = inOrderSplayTree[index].rstrip('\n')
    # Separate depths from values
    inOrderSplayDepths = []
    for i in inOrderSplayTree:
        inOrderSplayDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: inOrderSplayTree.csv cannot be found.')

graph("In Order Splay", inOrderSplayDepths)

try:
    infile = open("../data/inOrderTree.csv", 'r')
    header = infile.readline()
    inOrderTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(inOrderTree)):
        inOrderTree[index] = inOrderTree[index].rstrip('\n')
    # Separate depths from values
    inOrderTreeDepths = []
    for i in inOrderTree:
        inOrderTreeDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: inOrderTree.csv cannot be found.')

graph("In Order Tree", inOrderTreeDepths)

try:
    infile = open("../data/shuffledAVLTree.csv", 'r')
    header = infile.readline()
    shuffledAVLTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(shuffledAVLTree)):
        shuffledAVLTree[index] = shuffledAVLTree[index].rstrip('\n')
    # Separate depths from values
    shuffledAVLDepths = []
    for i in shuffledAVLTree:
        shuffledAVLDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: shuffledAVLTree.csv cannot be found.')

graph("Shuffled AVL Tree", shuffledAVLDepths)

try:
    infile = open("../data/shuffledSplayTree.csv", 'r')
    header = infile.readline()
    shuffledSplayTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(shuffledSplayTree)):
        shuffledSplayTree[index] = shuffledSplayTree[index].rstrip('\n')
    # Separate depths from values
    shuffledSplayDepths = []
    for i in shuffledSplayTree:
        shuffledSplayDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: shuffledSplayTree.csv cannot be found.')

graph("Shuffled Splay Tree", shuffledSplayDepths)

try:
    infile = open("../data/shuffledTree.csv", 'r')
    header = infile.readline()
    shuffledTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(shuffledTree)):
        shuffledTree[index] = shuffledTree[index].rstrip('\n')
    # Separate depths from values
    shuffledTreeDepths = []
    for i in shuffledTree:
        shuffledTreeDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: shuffledTree.csv cannot be found.')

graph("Shuffled Tree", shuffledTreeDepths)

try:
    infile = open("../data/spotifyAVLTree.csv", 'r', encoding='utf-8')
    header = infile.readline()
    spotifyAVLTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(spotifyAVLTree)):
        spotifyAVLTree[index] = spotifyAVLTree[index].rstrip('\n')
    # Separate depths from values
    spotifyAVLDepths = []
    for i in spotifyAVLTree:
        spotifyAVLDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: spotifyAVLTree.csv cannot be found.')

graph("Spotify AVL Tree", spotifyAVLDepths)

try:
    infile = open("../data/spotifySplayTree.csv", 'r', encoding='utf-8')
    header = infile.readline()
    spotifySplayTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(spotifySplayTree)):
        spotifySplayTree[index] = spotifySplayTree[index].rstrip('\n')
    # Separate depths from values
    spotifySplayDepths = []
    for i in spotifySplayTree:
        spotifySplayDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: spotifySplayTree.csv cannot be found.')

graph("Spotify Splay Tree", spotifySplayDepths)

try:
    infile = open("../data/spotifyTree.csv", 'r', encoding='utf-8')
    header = infile.readline()
    spotifyTree = infile.readlines()
    infile.close()
    # remove \n from items in the list
    for index in range(len(spotifyTree)):
        spotifyTree[index] = spotifyTree[index].rstrip('\n')
        # Separate depths from values
    spotifyTreeDepths = []
    for i in spotifyTree:
        spotifyTreeDepths.append(i.split(',')[1])

except IOError:
    print('FILE ERROR: spotifyTree.csv cannot be found.')

graph("Spotify Tree", spotifyTreeDepths)
