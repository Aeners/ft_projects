import styled from 'styled-components';

export const SWrapper = styled.div`
  width: 100vw;
  height: 100vh;
  position: relative;
  overflow: hidden;
`;

export const SBackground = styled.img`
  position: absolute;
  height: 100vh;
`;

export const SWrapperBoard = styled.div`
  position: absolute;
  z-index: 1;
  height: 100vh;
  width: 100vw;
  left: 50%;
  top: 50%;
  transform: translateX(-50%) translateY(-50%);
  text-align: center;
`;

export const SOverlay = styled.div`
  position: absolute;
  background-color: black;
  opacity: 0.8;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  z-index: 2;
  text-align: center;
`

export const SText = styled.p`
  color: white;
  font-size: 32;
`