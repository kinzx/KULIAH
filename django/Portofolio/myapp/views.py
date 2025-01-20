from django.shortcuts import render, HttpResponse

# Create your views here.
def home(request):
    return HttpResponse("Hello, world! This is the homepage.")

def member(request):
    return HttpResponse("Hello, world! This is the")
