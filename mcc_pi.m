function[zno, zun]=mcc_pi(snt)

%Funkcija glede na podano število nakjučnih točk n vrne matriki točk, ki se
%nahajajo znotraj kroga, in točk, ki se nahajo znotraj kvadrata.

    rng(1) %seme - zagotovimo ponavljanje nakjlučnih števil
    x=-1+(1-(-1)).*rand(1, snt); %naključna koordinata po dolžini pravokotnika
    y=-1+(1-(-1)).*rand(1, snt); %naključna koordinata po širini pravokotnika
    r=1; %polmer kroga

    l=sqrt(x.^2+y.^2)<=r; %logično preverjanje (vrne binarno vrednost glede na izpolnjenost trditve) enačbe krožnice

    nx=l.*x; %x koordinata točk po preverjanju
    ny=l.*y; %y koordinata točk po preverjanju
    nx(nx==0)=nan; %0 iz logičnega prevejanja nadomesti z nan
    ny(ny==0)=nan; %0 iz logičnega prevejanja nadomesti z nan
    nx=rmmissing(nx); %izbriše vnose nan
    ny=rmmissing(ny); %izbriše vnose nan
    nx=nx'; %transponiranje v stolpični vektor
    ny=ny'; %transponiranje v stolpični vektor

    zno=[nx, ny]; %matrika koordinat točk znotraj kroga
    zun=[x', y']; %matrika koordinat točk znotraj kvadrata

end
