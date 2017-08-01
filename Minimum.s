                .syntax     unified
                .cpu        cortex-m4
                .text
                .thumb_func
                .align      2

// int minimum_asm(int data[], int count) ;

                .global     minimum_asm
minimum_asm:    LDR         R2,=1               //R2 <- i = 1
                LDR         R3,[R0,0]           //R3 <- min = data[0]
Loop:           CMP         R2,R1               //Compare i to count
                BGE         End                 //i >= count
                LDR         R12,[R0,R2,LSL 2]   //R12 <- data[i]
                CMP         R12,R3              //Compare data[i] to min
                IT          LT                  //data[i] < min
                LDRLT       R3,[R0,R12]         //R3 <- min = data[i]
                ADD         R2,R2,1             //R2 <- i++
                B           Loop                //Branch to top of loop
End:            MOV         R0,R3               //R0 <- min
                BX          LR                  //Return min
                .end
