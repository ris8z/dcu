% child , parent
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
mother(X, Y):-
    female(X),
    parent(Y, X).

sister(X, Y):-
    female(X),
    parent(X, P),
    parent(Y, P),
    X \= Y.

aunt(X, Y):-
    parent(Y, P),
    sister(X, P).
%Q2
sibling(X, Y):-
    parent(X, P),
    parent(Y, P),
    X \= Y.

cousin(X,Y):-
    parent(X, P1),
    parent(Y, P2),
    sibling(P1, P2).

parentalgrandmother(X, Y):-
    mother(X, F),
    male(F),
    parent(Y, F).
%Q3
fizzbang([],[]).
fizzbang([Head|TailX], [Head|TailL]):-
    (Head mod 3 =:= 0; Head mod 5 =:= 0),
    fizzbang(TailX, TailL),!.
fizzbang([Head|Tail], L):-
    (Head mod 3 =\= 0, Head mod 5 =\= 0),
    fizzbang(Tail, L),!.

