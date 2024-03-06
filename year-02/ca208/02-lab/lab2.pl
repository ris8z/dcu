book(illiad,homer,study,500).
book(c,richie,study, 150).
book(ntbible,sams,reference,480).
book(ntfordummies,bob, reference,200).
book(montypython,me,comedy,300).
book(pythonalgorithms,david,study, 225).
book(masacre,dillenger,crime,180).
book(lilacbus,binchey,fiction,200).
book(fabuls, me, drama, 180).

build(L):-
    findall(book(T,A,G,S), book(T,A,G,S), L).

%gendere different from study and reference
holiday(_, []).
holiday(book(T, A, _,_), [book(Title, Author, Genere, Size)|_]):-
    T = Title,
    A = Author,
    Genere \== study,
    Genere \== reference,
    Size < 400.
holiday(B, [_|OtherBooks]):-
    holiday(B, OtherBooks).

%revisioin genere = study or = refrence size > 300
study_or_reference(X):-
    X == study; X == reference.

revision(_,[]).
revision(book(T, A, _, _), [book(Title, Author, Genere, Size)|_]):-
    T = Title,
    A = Author,
    study_or_reference(Genere),
    Size > 300.
revision(B, [_|OtherBooks]):-
    revision(B, OtherBooks).

%Literart genere must be drama

literary(_,[]).
literary(book(T,A,_,_), [book(Title, Author, Genere, _)|_]):-
    T = Title,
    A = Author,
    Genere == drama.
literary(B, [_|OtherBooks]):-
    literary(B, OtherBooks).

%Leisure either comedy or fiction
comedy_or_fiction(X):-
    X == comedy; X == fiction.

leisure(_,[]).
leisure(book(T, A, _, _), [book(Title, Author, Genere, _)|_]):-
    T = Title,
    A = Author,
    comedy_or_fiction(Genere).
leisure(B, [_|OtherBooks]):-
    leisure(B, OtherBooks).




