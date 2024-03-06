


myElem(X, [X|_]).
myElem(X, [_|Tail]):- myElem(X, Tail).


myHead(X, [X|_]).

myLast(X, [X]).
myLast(X, [_|Tail]):- myLast(X, Tail).

myTail(X, [_|X]).


myAppend([], L, L).
myAppend([Head|Tail], L, [Head|L3]):- myAppend(Tail, L, L3).

myReverse([X], [X]).
myReverse([Head|Tail], L):-
    myReverse(Tail, L1),
    myAppend(L1, [Head], L).


myDelete(X, [X|Tail], Tail).
myDelete(X, [Y|Tail], [Y|Tail1]):- myDelete(X, Tail, Tail1).
