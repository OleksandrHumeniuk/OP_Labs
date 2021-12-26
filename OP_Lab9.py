str = input("Enter string: ") # User's string

minLan = int(input("Enter minimum length of words: ")) # Minimum length of words in user's string


listOfWords = str.split() # A list that contains all words from the user's string

for i in range (len(listOfWords)-1, -1, -1 ): 
    
    if len(listOfWords[i]) < minLan: # If the word's length is smaller than minLan, it gets deleted from the list
        del listOfWords[i]

        
print("Updated string:",' '.join(listOfWords)) # Prints all words from the updated list, separated by a whitespace
