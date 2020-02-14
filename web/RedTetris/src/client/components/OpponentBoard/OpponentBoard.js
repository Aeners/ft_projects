import React from 'react';

import { SOpponentBoard, SWrapper, SBlock } from './styles';

const OpponentBoard = () => {
  const Map = [];
  for (let index = 0; index < 200; index++) {
    Map.push(<SBlock key={index} />);
  }

  return (
    <SOpponentBoard>
      <SWrapper>
        {Map}
      </SWrapper>
    </SOpponentBoard>
  );
};

export default OpponentBoard;
