import type { NextPage } from "next";
import Head from "next/head";
import styles from "../styles/Home.module.css";
//import data from "./test_data.json";
import data from "./full_data_1.json";

class Board {
  layout: number[][];
  covered: boolean[][];
  height: number;
  width: number;

  constructor(layout: number[][]) {
    this.layout = layout;
    this.height = layout.length;
    this.width = layout[0].length;
    this.covered = [];
    for (let i = 0; i < this.height; ++i) {
      this.covered.push([]);
      for (let j = 0; j < this.width; ++j) {
        this.covered[i].push(false);
      }
    }
    console.log(layout);
  }

  mark(v: number) {
    for (let i = 0; i < this.height; ++i) {
      for (let j = 0; j < this.width; ++j) {
        if (this.layout[i][j] === v) {
          this.covered[i][j] = true;
          console.log(`Covering ${v} at ${i},${j}`);
        }
      }
    }

    if (this.isComplete()) {
      const partialScore = this.sumUnmarked();
      console.log(this.covered);
      console.log(this.layout);
      return partialScore * v;
    } else {
      return 0;
    }
  }

  sumUnmarked() {
    let sum = 0;
    for (let i = 0; i < this.height; i++) {
      for (let j = 0; j < this.width; ++j) {
        if (!this.covered[i][j]) {
          sum += this.layout[i][j];
        }
      }
    }
    return sum;
  }

  isComplete() {
    for (let i = 0; i < this.height; i++) {
      let complete = true;
      for (let j = 0; j < this.width; ++j) {
        if (!this.covered[i][j]) {
          complete = false;
          break;
        }
      }

      if (complete) {
        return true;
      }
    }

    for (let j = 0; j < this.height; j++) {
      let complete = true;
      for (let i = 0; i < this.width; ++i) {
        if (!this.covered[i][j]) {
          complete = false;
          break;
        }
      }

      if (complete) {
        return true;
      }
    }

    return false;
  }
}

const Home: NextPage = () => {
  let boards: Board[] = [];
  let complete: boolean[] = [];
  let numWon = 0;
  console.log(`Num Boards: ${data.boards.length}`);

  /// make boards
  for (let i = 0; i < data.boards.length; ++i) {
    boards.push(new Board(data.boards[i]));
    complete.push(false);
  }

  for (let i = 0; i < data.draws.length; ++i) {
    console.log(`Drawing: ${data.draws[i]}`);
    let winningScore = 0;
    for (let b = 0; b < data.boards.length; ++b) {
      if (complete[b]) {
        continue;
      }

      winningScore = boards[b].mark(data.draws[i]);
      if (winningScore > 0) {
        console.log(`Win ${numWon}, board: ${b}, score: ${winningScore}`);
        complete[b] = true;
        numWon += 1;
      }
    }
  }

  return (
    <div className={styles.container}>
      <Head>
        <title>Day 4</title>
        <meta name="description" content="Generated by create next app" />
        <link rel="icon" href="/favicon.ico" />
      </Head>

      <main className={styles.main}>
        <p className={styles.description}>
          <code className={styles.code}>pages/index.tsx</code>
        </p>
      </main>

      <footer className={styles.footer}></footer>
    </div>
  );
};

export default Home;
