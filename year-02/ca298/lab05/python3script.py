import requests

num1 = 5
num2 = 6
url = 'http://127.0.0.1:8000/add?num1={}&num2={}'.format(num1, num2) # string interpolation
resp = requests.get(url) # make a get request to this url and save the response in resp
json_response = resp.json() # get the json response as a dict
print(json_response)
result = json_response['result'] # get the value out of the dict and save it to a variable
print(result)

