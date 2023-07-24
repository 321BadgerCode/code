!badger
CHARACTER FUNCTION get_str(int)
	IMPLICIT NONE

	INTEGER,INTENT(IN)::int

	CHARACTER(len=8)::fmt
	CHARACTER(len=5)::str

	fmt="(I5.5)"

	WRITE (str,fmt) int

	get_str=str
END FUNCTION get_str

INTEGER FUNCTION get_int(str)
	IMPLICIT NONE

	CHARACTER(len=:),INTENT(IN),ALLOCATABLE::str

	INTEGER::int

	READ (unit=str,fmt=*) int

	get_int=int
END FUNCTION get_int

FUNCTION get_trim(string)
	CHARACTER string*(*)

	jl=1
	i=len(string)

	DO WHILE (i.gt.jl)
		IF(ichar(string(i:i)).gt.ichar(' ')) jl=i
		i=i-1
	END DO

	get_trim=jl
END FUNCTION get_trim

FUNCTION get_len(string)
	CHARACTER string*(*)

	jl=0
	i=len(string)

	DO WHILE (i.gt.jl)
		if(ichar(string(i:i)).gt.ichar(' ')) jl=i
		i=i-1
	END DO

	get_len=jl
END FUNCTION get_len

INTEGER FUNCTION get_bin(dec)
	IMPLICIT NONE

	INTEGER,INTENT(IN)::dec

	INTEGER::bin=0
	INTEGER::power=0
	INTEGER::b1=0

	b1=dec

	DO WHILE(b1>0)
		bin=bin+(MOD(b1,2)*(MOD(b1,2)*(10**power)))
		power=power+1
		b1=b1/2
	END DO

	get_bin=bin
END FUNCTION get_bin

CHARACTER FUNCTION get_base(dec,base)
	CHARACTER,EXTERNAL::get_str
	CHARACTER,EXTERNAL::get_int
	IMPLICIT NONE

	INTEGER,INTENT(IN)::dec
	INTEGER,INTENT(IN),OPTIONAL::base;INTEGER::base2=10

	INTEGER::dec2=0
	CHARACTER(len=:),ALLOCATABLE::b1
	INTEGER::val=0
	CHARACTER(len=:),ALLOCATABLE::str
	INTEGER::a=0

	IF(present(base)) base2=base

	dec2=dec
	str=get_str(dec)

	DO WHILE(dec2>0)
		val=get_int(str(a:a))*(base2**a)

		IF(dec2>=val) THEN
			dec2-=val
			b1(a:a)='1'
		ENDIF
		a+=1
	END DO

	get_base=b1
END FUNCTION get_base

INTEGER FUNCTION get_dec(bin)
	IMPLICIT NONE

	CHARACTER(len=:),ALLOCATABLE,INTENT(IN)::bin
END FUNCTION get_dec

REAL*4 FUNCTION get_add(a1,a2)
	IMPLICIT NONE

	REAL*4,INTENT(IN)::a1
	REAL*4,INTENT(IN)::a2

	get_add=a1+a2
END FUNCTION get_add

PROGRAM main
	IMPLICIT NONE

	REAL*4::get_add,n1
	INTEGER::get_bin,bin

	CHARACTER(len=:),ALLOCATABLE::t1

	n1=15.0

	bin=get_bin(5)
	PRINT *,"bin. of 5: ",bin

	PRINT *,"sum ex.: ",bin,"+",n1,"=",get_add(REAL(bin),n1)
END PROGRAM main
!get_dec
!get_bin return CHARACTER

!4^2=16 ; default is 64-bit
!max=2*(16^2)
!all=(max*2)-1
!all = 1,023

!call, subroutine
