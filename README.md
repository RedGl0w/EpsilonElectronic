# numworks' epsilon electronic app
An experiment of an electronic app for [numworks' epsilon](https://github.com/numworks/epsilon)

## Compiling

```
git clone https://github.com/RedGl0w/EpsilonElectronic.git apps/electronic
```
For compiling with this app, add this flag :
```
EPSILON_APPS='calculation graph code statistics probability solver sequence regression settings electronic'
```
Exemple (build simulator) :
```
make PLATFORM=simulator EPSILON_APPS='calculation graph code statistics probability solver sequence regression settings electronic'
```
