function [player2]= problem436(iterations)
    digits(13);
    player2=0;
    for count=1:iterations
       sum=0;
       while sum<1
          latest1=rand();
          sum=sum+latest1;
       end
       while sum<2
          latest2=rand();
          sum=sum+latest2;
       end
       if latest1<latest2
           player2=player2+1;
       end
       disp(vpa(player2/count));
    end
end

