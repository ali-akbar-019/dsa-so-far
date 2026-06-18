from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.pipeline import Pipeline


texts = [
    "Pakistani people like politics",
    "Imran khan is a great politician",
    "Politics is for grown ups",
    "Benazeer was the first female prime minister of pakistan", 
    "Quaid e azam was a great man",
    "New movie of the spider man is out",
    "Can we go to cinema and watch movie?",
    "I dont like this",
    "I hate you"
]

labels =[
   "politics","politics", "politics","history","history", "movies", "movies", "negative", "negative"
]

model = Pipeline([
    ("vectorizer", CountVectorizer(stop_words="english")),
    ("classifier", MultinomialNB())
])

model.fit(texts, labels)

new_sentence = ["I like politics"]
prediction = model.predict(new_sentence)

print("Sentence: ", new_sentence[0])
print("Prediction: ", prediction[0])