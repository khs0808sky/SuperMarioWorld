![CommonToMini](https://github.com/user-attachments/assets/9e183aae-1cc3-402a-9d17-fee28982e0ef)# SuperMarioWorld
> **2D Platform Game Portfolio**<br>

- **게임규칙** <br>
움직이는 몬스터(밤바, 땡감바)를 제한시간(100초)안에 모두 잡으면 클리어<br><br>
- **조작법** <br>
  
|키|조작|
|:---|:---|
|←|왼쪽 이동|
|→|오른쪽 이동|
|↑|위 보기|
|↓|쭈그리기|
|Z|스핀 점프|
|X|점프|
|C|달리기|
|R|게임오버 or 게임클리어 시 재시작|

## Contents
- ### [MainScreen](#mainscreen)<br>
- ### [UI](#ui)<br>
- ### [BlockTile](#blocktile)<br>
- ### [Player](#player)<br>
- ### [PlayerMovement](#playermovement)<br>
- ### [PlayerStatusChange](#playerstatuschange)<br>
- ### [Enemy](#enemy)<br>
- ### [EnemyMovement](#enemymovement)<br>
- ### [EnemyKill](#enemykill)<br>
- ### [GameRule](#gamerule)<br>

<br><br><br><br><br><br><br><br><br><br>
## MainScreen
![image](https://github.com/user-attachments/assets/cf6db7bd-0261-4e4f-9d8a-4fbc2306f345)

## UI
- **남은 체력**<br>
![image](https://github.com/user-attachments/assets/a9f9fe0d-bfdd-4427-95aa-db59e1cd6424)
![image](https://github.com/user-attachments/assets/89d57b1b-34ee-4b64-ad31-f71e01fb83d2)
![image](https://github.com/user-attachments/assets/645839ee-d1f4-43fb-9c24-fd907bd5e761)

- **게임 목표**<br>
![image](https://github.com/user-attachments/assets/6bbbab7f-b5a7-4d9a-b5ad-eb4c2cacdb30)

- **남은 시간**<br>
![image](https://github.com/user-attachments/assets/4b2f215c-ab4e-4266-8348-5d1976cf5b14)

- **게임 오버**<br>
![image](https://github.com/user-attachments/assets/4573ad1a-d32d-49c5-aabc-46b2c760a88b)

- **게임 클리어**<br>
![image](https://github.com/user-attachments/assets/0722e2ec-d2df-4b22-b2ec-aa7a1d75d564)

## BlockTile
|종류|외형|특성|예시|
|:---:|:---:|:---:|:---:|
|땅 블록|![image](https://github.com/user-attachments/assets/b47c21f8-a94f-4389-ab3d-18a5acffd03d)|사방이 막힌 블록|![GroundTile](https://github.com/user-attachments/assets/b679fcbc-e51a-4293-a3db-9806d9e95000)|
|돌 블록|![image](https://github.com/user-attachments/assets/c25a9c81-9bfc-41b4-8547-10b1d39f310a)|사방이 막힌 블록|![StoneTile](https://github.com/user-attachments/assets/46af8ae5-2f2c-471a-b95b-126a47380eb6)|
|버섯 블록|![image](https://github.com/user-attachments/assets/fabc0e29-ffea-4e5e-b8f5-07bc40c2647f)|위에서만 밟히는 블록|![MushroomTile](https://github.com/user-attachments/assets/36c1a83d-f65d-4d5d-80c1-3ee1c361bbbc)|
|구름 블록|![image](https://github.com/user-attachments/assets/8b77751c-6f9f-4f80-b065-db8130db8e81)|위에서만 밟히는 블록|![CloudTile](https://github.com/user-attachments/assets/e4ee0506-dfe4-40ce-bc5d-a0ab966d67db)|
|다리 블록|![image](https://github.com/user-attachments/assets/0e5c04c9-130e-4c1b-ad43-5ba2a7be1ed8)|위에서만 밟히는 블록|![BridegeTile](https://github.com/user-attachments/assets/39b33044-895d-4ed3-bdbd-219768ebad82)|

## Player
|상태|외형|
|:---:|:---:|
|미니마리오|![image](https://github.com/user-attachments/assets/b621a3a8-f70a-4896-8be1-5045dd17a25b)|
|일반마리오|![image](https://github.com/user-attachments/assets/a924628b-5949-400b-a5a1-cfecd9fde872)|
|파이어마리오|![image](https://github.com/user-attachments/assets/8444a61e-2454-45ae-bb95-0d042c38b151)|

## PlayerMovement
|동작|움직임|
|:---:|:---:|
|정지<br>위쪽 쳐다보기<br>쭈그리기|![Idle_Up_Down](https://github.com/user-attachments/assets/81373ff4-1d29-4a94-8c96-6cd53b8bcfb1)|
|걷기|![Walk](https://github.com/user-attachments/assets/c49257d2-a226-4b22-934f-50a962074b22)|
|달리기<br>미끄러지기|![Run_Skid](https://github.com/user-attachments/assets/09880e8a-5034-4671-9c33-e33c5ff30746)|
|낮은 점프<br>높은 점프<br>낮은 쭈그리기점프<br>높은 쭈그리기점프<br>낮은 스핀점프<br>높은 스핀점프|![Jump_CrouchJump_SpinJump](https://github.com/user-attachments/assets/e5c7a9a5-9ce0-4b4a-b55b-3d9a56e17f50)|
|달리기 점프|![RunJump](https://github.com/user-attachments/assets/4fecf2c1-ae07-48af-8c79-5a333458dc59)|
|죽기|![Dead](https://github.com/user-attachments/assets/62cc25b1-bb14-48a9-a1e9-f118648b1900)|

## PlayerStatusChange
|상태변화|모습|
|:---:|:---:|
|파이어마리오 → 일반마리오|![FireToCommon](https://github.com/user-attachments/assets/d93f6307-5fde-4166-ac79-b1f04c665941)|
|일반마리오 → 미니마리오|![CommonToMini](https://github.com/user-attachments/assets/9d618e51-1442-4651-a89c-45592d7859b6)|

## Enemy
|이름|상태|외형|
|:---:|:---:|:---:|
|밤바|이동형|![image](https://github.com/user-attachments/assets/4305fdd4-eb8e-4d67-b474-f6996b58449b)|
|땡감바|이동형|![image](https://github.com/user-attachments/assets/11ad2e27-5783-43f9-bae3-1560bb04ff1e)|
|블랙뻐끔|고정형|![image](https://github.com/user-attachments/assets/f58379f1-60e8-4536-9463-97856ae16b19)|

## EnemyMovement
|종류|움직임|
|:---:|:---:|
|밤바|![BambaMove](https://github.com/user-attachments/assets/cecc1b55-1411-4ab6-a2f7-b7822e841682)|
|땡감바|![DdanggambaMove](https://github.com/user-attachments/assets/1cd73cf9-4ce9-4da0-923e-0a0977dd02d0)|
|블랙뻐끔|![BlackbuggeumMove](https://github.com/user-attachments/assets/26a5eb2f-b9f1-4dfa-933c-127073ee9747)|

## EnemyKill
> 스핀점프를 통해 밤바 & 땡감바를 처치할 수 있다<br>

|상황|상태|설명|
|:---:|:---:|:---:|
|일반&쭈그리기 점프로 밟음|![JumpEnemy](https://github.com/user-attachments/assets/45abab32-918f-49bd-8552-378cbbe02265)|적이 뒤집힘|
|적을 밟은 후 시간이 지났을 때|![ReviveEnemy](https://github.com/user-attachments/assets/2cdb9638-e178-4b6a-8f54-16189364413d)|몸부림 치며 부활|
|뒤집혀진 적을 스핀점프로 밟음|![1_SpinKill](https://github.com/user-attachments/assets/a769fb0b-d1f8-48d9-af37-76c20eb5749d)|적을 처치함|
|스핀 점프로 밟음|![2_SpinKill](https://github.com/user-attachments/assets/467f9e54-a136-4597-b738-c9ed4db5cb00)|적을 처치함|

## GameRule
|조건|결과|예시|
|:---:|:---:|:---:|
|밤바와 땡감바를 모두 처치|클리어|![GameClear](https://github.com/user-attachments/assets/f34e93a0-03fe-4429-b3af-e3f1e18e7dbf)|
|미니마리오에서 피격당함|게임오버|![GameOver](https://github.com/user-attachments/assets/0484cb77-3e81-4cee-acef-b2037c96c9de)|
|제한시간을 모두 소진|게임오버|![GameOver](https://github.com/user-attachments/assets/fc2f8d64-fd26-4a8a-9dd2-d019ddf3ad21)|
|메시지 출력 후 R버튼 누름|재시작|![GameRestart](https://github.com/user-attachments/assets/3c4d1280-dc40-41d0-927e-6cef9b44c9f0)|
