import mcc_pi.*


n=10^3; %število generiranih točk


[pi_num, odstopanje]=area_pi(n) %klic funkcije
[zno, zun]=mcc_pi(n);

lok={@(t) sqrt(1-t.^2); @(t) -sqrt(1-t.^2)}; %anonimne funkcija, ki nam podaja točke na krožnem loku

figure (1)
scatter(zun(:, 1), zun(:,end), 3,'b') %na graf nariše točke znotraj kvadrata
hold on
scatter(zno(:, 1), zno(:,end), 3,'r') %na graf nariše točke znotraj kroga
fplot(lok{1}, [-1, 1], 'g', 'LineWidth',2) %na graf nariše točke na zgornji polovici loka
fplot(lok{2}, [-1, 1],'g', 'LineWidth',2) % na graf nariše točke na spodnj polovici loka
axis equal 
xlim([-1, 1]) 
ylim([-1, 1]) 
title({['Določitev vrednosti števila \pi s pomočjo'] ['metode Monte Carlo, n= ' num2str(n)]})
xlabel('x') 
ylabel('y')
legend({'Točke zunaj kroga','Točke znotraj kvadrata', 'Točke na loku krožnice'},'Location','southeastoutside')
hold off

function [pi_num, odstopanje]=area_pi(n)
    
%Funkcija glede na podano število nakjlučno generiranih točk n pokliče
%funkcijo mcc_pi in izračuna vrednost števila \pi in njegovo odstopanje od
%shranjene vrednosti v Matlabu.

    [zno, zun]=mcc_pi(n);
    pi_num=numel(zno)/numel(zun)*4;
    odstopanje=pi_num-pi; 

end

