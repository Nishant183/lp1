from textblob import *
import tweepy

def getpercentage(a,b):
	x=100*(float(a)/float(b))
	return x

consumerKey='hxmtbU8L3zADlJbSbmY45sI0E'
consumerSecret='k1fkMUji9oOhK0R6AoPYHA78GXzedf0KKyBkpzP3Z8uqNykjMh'
accessToken='1056038999624568832-5LMFRDZnx3UEuWNl30gfK8csH08Qf6'
accessTokenSecret='kKtnowes5bjnlwMfbdvFpDNVyMvNJtcmdMACOWa5fL2sr'

auth=tweepy.OAuthHandler(consumer_key=consumerKey,consumer_secret=consumerSecret)
auth.set_access_token(accessToken,accessTokenSecret)
api=tweepy.API(auth)

search=input('Enter the search term->')
n=int(input('Enter number of tweets->'))

tweets=tweepy.Cursor(api.search,q=search,lang='English').items(n)

positive,negative,neutral=0,0,0
for tweet in tweets:
	print(tweet.text)
	x=TextBlob(tweet.text)
	if x.sentiment.polarity==0:
		neutral+=1
	elif x.sentiment.polarity<0:
		negative+=1
	else:
		positive+=1
a,b,c=format(getpercentage(neutral,n),'.2f'),format(getpercentage(negative,n),'.2f'),format(getpercentage(positive,n),'.2f')
print(a,b,c)
