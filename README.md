# 42 term3d

## 概要

透視投影を使った3Dプロジェクション
- オブジェクトのファイルを読み込む
- 3次元の点をxy平面に正射影して基底変換する等角投影法に加えて、z値で割ることで奥行きを表現

## Demo

torus

![torus](https://user-images.githubusercontent.com/50983708/155822346-9bb660ce-6a98-473d-bf16-c0b33cdc2e97.gif)

cube

![cube](https://user-images.githubusercontent.com/50983708/155822351-1d074f37-cff1-4d4b-9c94-880a199a5bdf.gif)

## Usage

```zsh
git clone https://github.com/Masaya-Kamei/term3d.git --recursive;
cd term3d;
make;
./term3d [3d_file];
```

3d_file の例: `figures/torus.3d`

```txt
1.544456534909866,2.5718969675658103,5
1.761971793423513,2.4237940770708266,5.143797326596529
1.9618820122077107,2.251473437357552,5.2861578778387805
2.1421897544379007,2.0566568192963692,5.425659234156886
2.301093444755534,1.8412907661371358,5.560907544111532
2.4370053700135337,1.6075271442924646,5.690551451296798
2.5485675431812305,1.3577016425998492,5.813295596646668
2.634665271901884,1.0943104348908703,5.927913561234625
.....
```

## キーワード

`C`,`3Dプロジェクション`,`透視投影`,`ベクトル`,`正射影`,基底変換`,`軸周りの回転`

## Tool

- [my libft](https://github.com/Masaya-Kamei/libft) (42 useful functions)
- [Github Actions](https://docs.github.com/ja/actions) (CI/CD tool)
