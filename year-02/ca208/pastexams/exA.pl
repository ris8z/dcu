parent(carol, paul).
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
father(X,Y):-
    male(X),
    parent(Y, X).

sibling(X, Y):-
    parent(X, P),
    parent(Y, P),
    X \= Y.

brother(X, Y):-
    male(X),
    sibling(X, Y).

uncle(X,Y):-
    brother(X, P),
    parent(Y, P).

%Q2
cousin(X, Y):-
    parent(X, P),
    sibling(P, P1),
    parent(Y, P1).

maternalgrandmother(X,Y):-
    female(X),
    parent(Ymother, X),
    female(Ymother),
    parent(Y, Ymother).
%Q3
sum(0,[]).
sum(Sum, [Head|Tail]):-
    sum(TailSum, Tail),
    Sum is TailSum + Head.

minimum(X, [X]).
minimum(Min, [Head|Tail]):-
    minimum(TailMin, Tail),
    (Head < TailMin -> Min = Head; Min = TailMin),!.

