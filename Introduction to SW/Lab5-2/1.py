sentence=str(input())
words=sentence.split()
word_counts={}

for word in words:
    if word in word_counts:
        word_counts[word] += 1
    else:   
        word_counts[word] = 1
        
for words, count in word_counts.items():
    print(words,": ",count)       