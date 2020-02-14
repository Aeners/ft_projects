import React from 'react';

import { SBoard, SWrapper, SBlock } from './styles';

const Board = ({
  block,
  position,
  pieceGoingDown,
  pieceGoingLeft,
  pieceGoingRight,
}) => {
  const Map = [];

  for (let index = 0; index < 200; index++) {
    const onGridX = index % 10;
    const onGridY = parseInt(index / 10, 10);
    if (
      onGridY - position.y < block.length &&
      onGridX - position.x < block[0].length &&
      onGridY - position.y >= 0 &&
      onGridX - position.x >= 0
    ) {
      if (block[onGridY - position.y][onGridX - position.x]) {
        Map.push(<SBlock key={index} color="red" />);
      } else {
        Map.push(<SBlock key={index} />);
      }
    } else {
      Map.push(<SBlock key={index} />);
    }
  }

  const onKeyPressed = event => {
    if (event.keyCode === 39) {
      pieceGoingRight();
    } else if (event.keyCode === 37) {
      pieceGoingLeft();
    } else if (event.keyCode === 40) {
      pieceGoingDown();
    } else if (event.keyCode === 38) {
      console.log('NEED TO ROTATE THE PIECE');
    }
  };

  return (
    <SBoard onKeyDown={onKeyPressed} tabIndex="0">
      <SWrapper>{Map}</SWrapper>
    </SBoard>
  );
};

export default Board;
