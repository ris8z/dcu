
%rent(carol, paul).
parent(carol, jane).
parent(harry, tom).
parent(harry, mary).
parent(jim, tom).
parent(jim, mary).
parent(ann, tom).
parent(ann, mary).
parent(tim, harry).
parent(tim, carol).
parent(george, harry).
parent(george, carol).
parent(jenny, harry).
parent(jenny, carol).
parent(david, jim).
parent(david, joan).
parent(kate, jim).
parent(kate, joan).
parent(susan, dominic).
parent(susan, ann).
male(paul).
male(tom).
male(harry).
male(jim).
male(dominic).
male(tim).
male(george).
male(david).
female(jane).
female(mary).
female(carol).
female(joan).
female(ann).
female(jenny).
female(kate).
female(susan).

%Q1
mother(X,Y):-
    female(X),
    parent(Y, X).

sibling(X,Y):-
    parent(X, P),
    parent(Y, P),
    X \= Y.

uncle(X,Y):-
    male(X),
    sibling(X, P),
    parent(Y, P).

%Q3
cousin(X, Y):-
    parent(X, P1),
    parent(Y, P2),
    sibling(P1, P2).

paternalgrandmother(X,Y):-
    mother(X, F),
    male(F),
    parent(Y, F).

%Q3
oddsum(0,[]).
    oddsum(Sum, [Head|Tail]):-
    oddsum(TailSum, Tail),
    Flag is Head mod 2,
    Sum is TailSum + Head * Flag.

maximum(0,[]).
maximum(Max, [Head|Tail]):-
    maximum(TailMax, Tail),
    (Head > TailMax -> Max = Head; Max = TailMax).
