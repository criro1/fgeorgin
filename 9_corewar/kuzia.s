.name "Kuzia"
.comment  "Нафаня, сундук украли"

			ld		%0, r16
			zjmp	%:begin
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
			zjmp	%0
begin:		sti		r1, %:step1, %1
step1:		live	%0
			ld		%52, r2
			ld		%4, r3
			sti		r1, %:alive, %1
			sti		r1, %:alive2, %1
			sti		r1, %:alive3, %1
			sti		r1, %:live_fork, %1
			sti		r1, %:live_fork2, %1
			fork	%:cycle3
live_fork:	live	%0
			fork	%:cycle2
live_fork2:	live	%0
			fork	%:step1
			ld		%0, r5
cycle:		ldi		%-7, r5, r4
alive:		live	%0
			sti		r4, r5, %157
			add		r3, r5, r5
			and		r2, r5, r6
			sub		r6, r2, r7
			zjmp	%136
			ld		%0, r7
			zjmp	%:cycle

			ld		%0, r5
cycle2:		ldi		%-7, r5, r4
alive2:		live	%0
			sti		r4, r5, %157
			add		r3, r5, r5
			and		r2, r5, r6
			sub		r6, r2, r7
			zjmp	%136
			ld		%0, r7
			zjmp	%:cycle2

			ld		%0, r5
cycle3:		ldi		%-7, r5, r4
alive3:		live	%0
			sti		r4, r5, %157
			add		r3, r5, r5
			and		r2, r5, r6
			sub		r6, r2, r7
			zjmp	%136
			ld		%0, r7
			zjmp	%:cycle3
