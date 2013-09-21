function [player2]= problem436(iterations)
    digits(13);
    player2=0;
    for count=1:iterations
       sum1=0;
       sum2=0;
       while sum1<1
          latest1=rand();
          sum1=sum1+latest1;
       end
       while sum2<2
          latest2=rand();
          sum2=sum2+latest2;
       end
       if latest1<latest2
           player2=player2+1;
       end
       disp(vpa(player2/count));
    end
end

