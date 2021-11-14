### 이동
	Make Vector로 전체 월드 좌표 기준으로 이동시킬 수 있다
	SetActorLocation 함수를 Call. 옵션은 Sweep과 Teleport 두 가지가 있다. (순간이동임)
	Teleport는 통과하지만, Sweep은 벡터 이동을 하는 과정에서 부딪힐 물체가 있는지 검사한다.
	따라서 이론적으로는 Sweep을 통해 FPS에서 총알 피격 여부를 검사할 수 있다.
	
	
### 회전
	SetActorLocationAndRotation 함수를 통해 회전과 이동을 할 수 있다.
	회전에는 Make Rotator 함수를 이용한다.
	다만 일반적으로 회전을 시킨 후 이동을 시키면 월드 좌표 기준으로 물체가 이동한다.
	따라서 물체 좌표계 기준으로 회전 후 이동을 시켜주려면?
	Make Rotator -> Get Forward Vector -> Normalize 2D (Vector)
	
	
### Skeletal Mesh
	뼈대가 있는 것과 없는 것으로 나뉜다.
	웨폰은 뼈대가 있는 것(활은 뼈대가 줄과 대로 나뉨)도 있고 없는 것(주로 검 종류)도 있다.
	뼈대가 필요한 이유? -> 애니메이션 재생을 위해!
	Actor는 컨트롤러가 없음. Pawn(입력 키를 받을 수 있는 클래스)은 Actor를 상속함.
	Pawn은 입력을 받을 수는 있지만 실제로 움직임(애니메이션)은 없음. (Controller, Movement 클래스를 갖고 있음)
	따라서 Character : Pawn을 생성. Character은 실제로 움직이는 녀석.
	
### 인칭 바꾸기
	BluePrint에서 Mesh에 SpringArm->Camera 추가
	
### 엔진 - 입력
	축 매핑 : 계속 눌렀을 대 매핑 (이동, 마우스)
	액션 매핑 : 한 번, 두 번 눌렀을 때 매핑 (일반적인 공격)