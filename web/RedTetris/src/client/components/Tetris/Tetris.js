import React from 'react';

import {
  SWrapper,
  SBackground,
  SWrapperBoard,
  SOverlay,
  SText,
} from './styles';
import Board from '../Board';
import OpponentBoard from '../OpponentBoard/';

const Tetris = ({ gameHasStarted, startTheGame }) => {
  const onKeyPressed = event => {
    if (event.keyCode === 13) startTheGame();
  };

  return (
    <SWrapper>
      {!gameHasStarted && (
        <SOverlay onKeyDown={onKeyPressed} tabIndex="0">
          <SText>Waiting for other play or press Enter bar to play</SText>
        </SOverlay>
      )}
      <SWrapperBoard>
        <Board />
        <OpponentBoard />
      </SWrapperBoard>
      <SBackground src="https://www.destructoid.com//ul/486015-TETRIS.jpg" />
    </SWrapper>
  );
};

export default Tetris;
