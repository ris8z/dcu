


%Q1

class(0, zero):-!.
class(N, positive):- N >= 0,!.
class(N, negative):- N < 0,!.


%Q2

split([],[],[]).
split([Head|Tail1], [Head|Tail2], N):-
    Head >= 0,
    split(Tail1, Tail2, N),!.
split([Head|Tail1], P, [Head|Tail3]):-
    Head < 0,
    split(Tail1, P, Tail3),!.

%Q3

%my simple solution

fib(0,1).
fib(1,1).

fib(X, N):-
    X1 is X - 1,
    X2 is X - 2,
    fib(X1, N1),
    fib(X2, N2),
    N is N1 + N2.

%dinamic version from stackoverflow https://stackoverflow.com/questions/16358747/why-this-dynamic-version-of-fibonacci-program-is-incredibly-faster-then-this-oth

:- dynamic fibDyn/2.
:- retractall( fibDyn(_,_) ).

fibDyn(0,1).
fibDyn(1,1).

fibDyn(N,F) :- N > 1,
    N1 is N-1,
    fibDyn(N1,F1),
    N2 is N-2,
    fibDyn(N2,F2),
    F is F1+F2,
    asserta( (fibDyn(N,F):-!) ).

%prof solution

fib(0,1).
fib(1,1).

fib(X,N) :- X1 is X-1, X2 is X-2, fib(X1,N1), fib(X2,N2), N is N1 + N2, !.

