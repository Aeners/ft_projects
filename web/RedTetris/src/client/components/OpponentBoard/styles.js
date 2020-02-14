import styled from 'styled-components';

export const SOpponentBoard = styled.div`
  height: 300px;
  width: 150px;
  background-color: red;
  display: inline-block;
  z-index: 1;
  vertical-align: top;
  margin: 40px 0 0 20px;
`;

export const SWrapper = styled.div`
  height: 100%;
  width: 100%;
  display: flex;
  flex-direction: row;
  flex-wrap: wrap;
`;

export const SBlock = styled.div`
  height: 13px;
  width: 13px;
  border: 1px solid black;
  opacity: 0.2;
`;
